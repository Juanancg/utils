# main.py
import os 
import json
import logging 
import argparse

logging.basicConfig(
    format = '\033[38;2;255;97;3m[PyStartup]: \033[0m[%(asctime)s] [%(levelname)s]: %(message)s', level = logging.INFO
)

def str2bool(value):
    if isinstance(value, bool):
        return value
    if value.lower() in ('yes', 'true', 't', 'y', '1'):
        return True
    if value.lower() in ('no', 'false', 'f', 'n', '0'):
        return False
    raise argparse.ArgumentTypeError("Boolean value expected.")

def main():
    logging.info("Welcome to python opennings!")

    parser = argparse.ArgumentParser(
        description = 'Common python skeleton to start to code'
    )
    parser.add_argument(
        '--required_arg',
        required = True,
        help = "Required argument example."
    )

    parser.add_argument(
        '--modes',
        default = "none",
        required = False,
        choices = ["mode1", "mode2", "mode3"],
        help = "Some modes with choices."
    )

    parser.add_argument(
        '--bool_option',
        default = False,
        type = str2bool,
        required = True,
        help = "Bool option that accepts several formats."
    )

    args = parser.parse_args()

    logging.info("Your args are: bool_option: " + str(args.bool_option) + " - modes: " + str(args.modes) + " - required_arg: " + str(args.required_arg))

    # TODO: Way to read and write in a file
    # TODO: Exception
    # TODO: Dataframes


if __name__ == '__main__':
    main()
