import logging
import os

# Para loggear o no en fichero
VERBOSE = True
LOG_DIR = "/logs/"
LOG_NAME = "monitor_ssh"
LOG_FILE_PATH = os.path.join(LOG_DIR, LOG_NAME) + ".log"

class SingletonExample:

    _instance = None
    _initialized = False

    def __new__(cls):
        """Gestion de la instancia del singleton y lectura unica de la config

        Returns:
            Instancia
        """
        if cls._instance is None:
            cls._instance = super(SingletonExample, cls).__new__(cls)
            cls._instance._initialized = True
            cls._instance._init_class()

        return cls._instance
    
    def _init_class(self):
        # do the initialization
        return 
    
class SingletonLogger(SingletonExample):
    def _init_class(self):
        # Initialize logging
        self._init_logging()

    def _init_logging(self):
        if VERBOSE:
            open_file_mode = "a"
            if not os.path.exists(LOG_FILE_PATH):
                # If the file does not exist, create the directory and the file in write mode
                os.makedirs(os.path.dirname(LOG_FILE_PATH), exist_ok=True)
                open_file_mode = "w+"

            logging.basicConfig(
                filename=LOG_FILE_PATH,
                filemode=open_file_mode,
                format="%(asctime)s [%(name)s] %(levelname)s: %(message)s",
                datefmt="%d-%m-%Y %H:%M:%S",
                level=logging.DEBUG,
            )

    def push_log_msg(self, msg):
        if VERBOSE:
            logging.error(msg)

# Example usage:
logger_instance = SingletonLogger()
logger_instance.push_log_msg("This is an error message")