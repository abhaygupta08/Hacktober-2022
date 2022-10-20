import arcade
import yaml

from gamemanager import GameManager

def load_config():
    """ Load config data from config.yaml """

    with open("config.yaml", 'r') as stream:
        try:
            return yaml.safe_load(stream)
        except yaml.YAMLError as exc:
            print(exc)

def main():
    """ Main method """

    # load config
    GAME_CONFIG = load_config()

    # load game
    window = GameManager(GAME_CONFIG)
    window.setup()
    arcade.run()

if __name__ == "__main__":
    main()
    