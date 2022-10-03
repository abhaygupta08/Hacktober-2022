import arcade
import math

class Obstacle(arcade.Sprite):
    """ Obstacle class """

    def __init__(self, GAME_CONFIG, target, initial_rotation_position):
        """ Initialize obstacle """

        self.SPRITE_SCALING = GAME_CONFIG["general_settings"]["sprite_scaling"]
        self.KNIFE_IMAGE = GAME_CONFIG["assets_path"]["images"]["knife"]

        super().__init__(self.KNIFE_IMAGE, self.SPRITE_SCALING/2)

        self.center_x = 0
        self.center_y = 0
        self.rotation = 0
        self.target = target
        self.rotation_speed = self.target.TARGET_ROTATION_SPEED
        self.rotation_radius = self.target.height/2
        self.rotation_center = self.target.TARGET_POSITION
        self.initial_rotation_position = initial_rotation_position

        # Reshape the collision
        self.points = (
            (-self.width // 3, self.height // 2),
            (self.width // 3, -self.height // 2),
            (-self.width // 3, -self.height // 2),
            )

    def update(self):
        """ Movement and game logic """
        
        # Rotation angle must be added with the initial rotation and 90 degress
        self.rotation += self.target.TARGET_ROTATION_SPEED
        self.angle = self.rotation+self.initial_rotation_position+90
        self.center_x = (self.rotation_radius * math.cos(math.radians(self.rotation+self.initial_rotation_position))) + self.rotation_center[0]
        self.center_y = (self.rotation_radius * math.sin(math.radians(self.rotation+self.initial_rotation_position))) + self.rotation_center[1]
