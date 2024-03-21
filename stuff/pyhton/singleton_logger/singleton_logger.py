import logging
import os

# Para loggear o no en fichero
VERBOSE = True
LOG_DIR = "/logs/"
LOG_NAME = "monitor_ssh"
LOG_FILE_PATH = os.path.join(LOG_DIR, LOG_NAME) + ".log"
STDOUT_ENABLED = True
FILE_LOGGING_ENABLED = True

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

    root_logger = logging.getLogger()

    def _init_class(self):
        # Initialize logging
        self._init_logging()

    def _init_logging(self):
        if VERBOSE:

            log_formatter = logging.Formatter(
                "%(asctime)s [%(name)s] %(levelname)s: %(message)s",
                datefmt="%d-%m-%Y %H:%M:%S",
            )

            # Remove any existing handlers to prevent duplication
            SingletonLogger.root_logger.handlers.clear()

            # Add the logging to file
            if FILE_LOGGING_ENABLED:
                open_file_mode = "a"

                # If the file does not exist, create the directory and the file in write mode
                if not os.path.exists(LOG_FILE_PATH):
                    os.makedirs(os.path.dirname(LOG_FILE_PATH), exist_ok=True)
                    open_file_mode = "w+"

                file_handler = logging.FileHandler(filename=LOG_FILE_PATH, mode=open_file_mode)
                file_handler.setFormatter(log_formatter)
                SingletonLogger.root_logger.addHandler(file_handler)

            # If console logging is enabled, then add the handler
            if STDOUT_ENABLED:
                console_handler = logging.StreamHandler()
                console_handler.setFormatter(log_formatter)
                SingletonLogger.root_logger.addHandler(console_handler)

    def push_log_msg(self, msg):
        if VERBOSE:
            SingletonLogger.root_logger.error(msg)

# Example usage:
logger_instance = SingletonLogger()
logger_instance.push_log_msg("This is an error message")