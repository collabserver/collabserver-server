#!/usr/bin/python2.7
#
# Warning:
# Not working: changes are not persistant.
# Though may be used to print current settings.
#
# Description
# Set the environment variable for this project.
# For instance the env variable that points toward dependencies.

import os
import os.path
import signal
import sys

# Warning: if value is changed, must be changed in CMake as well
env_dependencies='DEPENDENCIES_DEVEL'


def promptCreateEnvVar(var_name):
    print("-> Set " + var_name + " environment variable.")
    current_value = os.getenv(var_name)
    if(current_value is None):
        print("Warning: " + var_name + " already exists!")
        print(var_name + ": " + current_value)

def createEnvVariable(var_name):
    print("* Create environment variable " + var_name)
    value = os.getenv(var_name)
    if(value is not None):
        print("[Error]: " + var_name + " already exists!")
        return -1
    path = raw_input("Path for " + var_name +": ")
    if(os.path.isdir(path)):
        os.environ[var_name] = path
        print(var_name + " successfully updated!")
        return 1
    else:
        print("[ERROR]: " + path + " is not a valid directory!")
        print(var_name + " not created.")
        return 1

def updateEnvVariable(var_name):
    value = os.getenv(var_name)
    if(value is None):
        print("[Error]: " + var_name + " doesn't exists!")
        return -1
    print("Old value: " + value)
    path = raw_input("New path for " + var_name +": ")
    if(os.path.isdir(path)):
        os.environ[var_name] = path
        print(var_name + " successfully updated!")
        return 1
    else:
        print("[ERROR]: " + path + " is not a valid directory!")
        print(var_name + " not updated.")
        return 1

def promptMenu():
    print("Menu")
    print(" 1- Print current environment settings")
    print(" 2- Create " + env_dependencies + " var")
    print(" 3- Update " + env_dependencies + " var")
    print(" 4- Exit")
    choice = raw_input("You choice: ")
    if(choice == '1'):
        print("")
        printCurrentEnv()
        raw_input("Press any way to continue...")
        return 1
    elif(choice == '2'):
        print("")
        print("[WARNING] not working. Must be set manually")
        raw_input("Press any way to continue...")
        #createEnvVariable(env_dependencies)
        return 1
    elif(choice == '3'):
        print("")
        print("[WARNING] not working. Must be set manually")
        raw_input("Press any way to continue...")
        #updateEnvVariable(env_dependencies)
        return 1
    else:
        return -1

def printCurrentEnv():
    print("* Current project environment settings:")
    value = os.getenv(env_dependencies)
    if(value is None):
        print(env_dependencies + ": variable doesn't exists!")
    else:
        print(env_dependencies + ": " + value)

def main():
    print("----- Project Configuration -----")
    print("To build and run the server, you need several dependencies.")
    print("You may place all these dependencies in a folder.")
    print(env_dependencies + " should point to this folder"),
    print("so that CMake is able to build the project.")
    print("") # Just line return
    printCurrentEnv()
    print("")
    while(promptMenu() is not -1):
        print("")
    print("See you")
    sys.exit(1)


def signalCtrlC(signal, frame):
    print("")
    print("See you!")
    sys.exit(0)

signal.signal(signal.SIGINT, signalCtrlC)

if(__name__ == '__main__') :
    main()
