import arcade
import random
from enum import Enum

class RotationMode(Enum):
    """ Store rotation mode in enum """
    NORMAL = 1
    REVERSE = 2
    BACK_AND_FORTH = 3
    FAST_AND_SLOW = 4

class Boss(arcade.Sprite):
    """ 
    Boss class
    """

    def __init__(self, GAME_CONFIG, scale_ratio=1, rotation_mode=None):
        """ Initialize target """

        self.SCREEN_WIDTH = GAME_CONFIG["general_settings"]["screen_width"]
        self.SCREEN_HEIGHT = GAME_CONFIG["general_settings"]["screen_height"]
        self.SPRITE_SCALING = GAME_CONFIG["general_settings"]["sprite_scaling"]
        self.TARGET_POSITION = (self.SCREEN_WIDTH//2, self.SCREEN_HEIGHT*(0.7))
        self.TARGET_ROTATION_SPEED = GAME_CONFIG["target_settings"]["rotation_speed"]
        self.TARGET_IMAGE = GAME_CONFIG["assets_path"]["images"]["boss"]["boss1"]

        super().__init__(self.TARGET_IMAGE, self.SPRITE_SCALING/scale_ratio)

        self.TARGET_HITTED_SOUND = GAME_CONFIG["assets_path"]["sounds"]["boss1_hitted"]
        self.TARGET_HITTED_SOUND = arcade.load_sound(self.TARGET_HITTED_SOUND)
        
        self.center_x = self.TARGET_POSITION[0]
        self.center_y = self.TARGET_POSITION[1]
        # self.angle = random.randrange(360)
        # self.change_angle = self.TARGET_ROTATION_SPEED
        
        self.hit_impact_animation = False
        self.original_position = self.center_y
        
        self.impact_animation_counter = 0
        self.rotation_animation_counter = 0
        self.rotation_state = None

        if rotation_mode is None:
            self.rotation_mode = random.choice(list(RotationMode))
        else:
            self.rotation_mode = rotation_mode

        # Override the rotation mode here for testing purposed
        self.rotation_mode = RotationMode.BACK_AND_FORTH
        
        if self.rotation_mode == RotationMode.NORMAL:
            pass
        elif self.rotation_mode == RotationMode.REVERSE:
            self.TARGET_ROTATION_SPEED = -self.TARGET_ROTATION_SPEED
        elif self.rotation_mode == RotationMode.FAST_AND_SLOW:
            self.rotation_state = "Decreasing"
        elif self.rotation_mode == RotationMode.BACK_AND_FORTH:
            self.rotation_state = "Back"
            self.rotation_direction = 1
        elif self.rotation_mode == "STATIC":
            self.TARGET_ROTATION_SPEED = 0
        else:
            pass
        
    def hit_impact(self):
        """ Initialize the "hit impact" state """

        self.hit_impact_animation = True
        self.impact_animation_counter = 3

    def update(self):
        """ Movement and game logic """

        # Rotate the target.
        # The arcade.Sprite class has an "angle" attribute that controls
        # the sprite rotation. Change this, and the sprite rotates.

        if self.rotation_mode == RotationMode.FAST_AND_SLOW:
            if self.rotation_state is "Decreasing":
                self.TARGET_ROTATION_SPEED -= 0.005
            if self.rotation_state is "Decreasing" and self.TARGET_ROTATION_SPEED <= 0:
                self.rotation_state = "Increasing"
            if self.rotation_state is "Increasing":
                self.TARGET_ROTATION_SPEED += 0.01
            if self.rotation_state is "Increasing" and self.TARGET_ROTATION_SPEED >= 3:
                self.rotation_state = "Decreasing"
        
        if self.rotation_mode == RotationMode.BACK_AND_FORTH:
            if self.rotation_state is "Back":
                self.TARGET_ROTATION_SPEED -= 0.01
            if self.rotation_state is "Back" and self.TARGET_ROTATION_SPEED <= -4:
                self.rotation_state = "Forth"
            if self.rotation_state is "Forth":
                self.TARGET_ROTATION_SPEED += 0.05
            if self.rotation_state is "Forth" and self.TARGET_ROTATION_SPEED >= 4:
                self.rotation_state = "Back"


        self.angle += self.TARGET_ROTATION_SPEED

        # Play the hit impact animation
        if self.hit_impact_animation and self.impact_animation_counter > 0:
            self.center_y += 3
            self.color = (255, 179, 179)
            self.impact_animation_counter -= 1
        else:
            self.color = (255, 255, 255)
            self.hit_impact_animation = False
            self.impact_animation_counter = 0
            self.center_y = self.original_position
        
