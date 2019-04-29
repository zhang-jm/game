

import thread
from subprocess import Popen
import time


def Game_Client():
    print("Starting Game Client...\n")
    client_cmd="./Game-Client-Network"
    client_handle = Popen(client_cmd, shell=True)


def Game_Server():
    print("Starting Game Server...\n")
    server_cmd="./Game-Server"
    server_handle = Popen(server_cmd, shell=True)

thread.start_new_thread(Game_Client, ())
thread.start_new_thread(Game_Server, ())


while 1:
    pass