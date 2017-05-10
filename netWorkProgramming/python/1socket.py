import socket
newSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

newSocket.connect(("localhost", 80))
newSocket.send("GET / HTTP/1.1 \n\n")
#newSocket.send("GET / HTTP/1.1 \n\n")


while(1):
    data = newSocket.recv(1024)
    if len(data)< 1:
        break
    print data


