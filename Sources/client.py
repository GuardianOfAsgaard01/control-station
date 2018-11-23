#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from socket import socket, AF_INET, SOCK_DGRAM

if len(sys.argv) < 2:
    print("Error!")
    sys.exit()

SERVER_IP   = 'x.x.x.x' #change this value according to your own network. 
#for learning if of your network, use ifconfig command for unix based systems/

PORT_NUMBER = 5000
SIZE = 1024
print ("Client sending packets to IP {0}, via port {1}\n".format(SERVER_IP, PORT_NUMBER))

mySocket = socket( AF_INET, SOCK_DGRAM )
myMessage1 = sys.argv[1] 

mySocket.sendto(myMessage1.encode('utf-8'),(SERVER_IP,PORT_NUMBER))

sys.exit()
