import arcade
import math

class KnifeCount(arcade.Sprite):
    """
    Knife count display class
    """

    def __init__(self, GAME_CONFIG, image_name, knife_count=0):
        """ Initialize knife count display """

        self.SCREEN_WIDTH = GAME_CONFIG["general_settings"]["screen_width"]
        self.SCREEN_HEIGHT = GAME_CONFIG["general_settings"]["screen_height"]
        self.SPRITE_SCALING = GAME_CONFIG["general_settings"]["sprite_scaling"]
        self.KNIFE_COUNT_FG = GAME_CONFIG["assets_path"]["images"]["knife_count"]["foreground"]
        self.KNIFE_COUNT_BG = GAME_CONFIG["assets_path"]["images"]["knife_count"]["background"]

        # Check whether the display is for background or foreground
        self.image_name = self.KNIFE_COUNT_FG
        if(image_name=="background"):
            self.image_name = self.KNIFE_COUNT_BG
        
        super().__init__(self.image_name, self.SPRITE_SCALING/1.2)
        
        # Automatically position the knife count image based on the number of knife count
        self.knife_count = knife_count
        self.center_x = self.SCREEN_WIDTH * 0.1
        self.center_y = (self.SCREEN_HEIGHT * 0.1 ) + (self.knife_count*self.SCREEN_HEIGHT*0.03)
