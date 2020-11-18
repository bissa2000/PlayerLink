//
// Created by hanzalah on 16/11/2020.
//

#include "Socket.h"

Socket::Socket(int family, int type, int flag) : socketIsClosed(false) {
    mSocketFD = ::socket(family,type,flag);
    if(mSocketFD == -1){
        throw SocketException("Error when creating Socket");
    }
}

Socket::Socket(int fd) :mSocketFD(fd), socketIsClosed(false){}

int Socket::getSocketDescriptor() const {return mSocketFD;}

#ifdef _WIN32

void Socket::close() {
    if(!socketIsClosed){
        ::closesocket(mSocketFD);
        socketIsClosed = true;
    }
}
#elif _unix_
void Socket::close() {
    if(!socketIsClosed){
        ::close(mSocketFD);
        socketIsClosed = true;
    }
}
#endif

std::string Socket::getAddress() const {
    sockaddr_in address;
    uint32_t addressLength = sizeof(address);
    if(getpeername(mSocketFD, (sockaddr *)&address, (socklen_t  *)addressLength) < 0){
        throw SocketException("Fetch of Remote Address Failed");
    }
    return inet_ntoa(address.sin_addr);
}

uint32_t Socket::getPort() const{
    sockaddr_in address;
    uint32_t addressLength = sizeof(address);
    if(getpeername(mSocketFD, (sockaddr *)&address, (socklen_t  *)addressLength) < 0){
        throw SocketException("Fetch of Remote Port Failed");
    }
    return ntohs(address.sin_port);
}
//
// WIP: Find portable or Win32API Equivalent of fcntl
// Currently Returns provided value.
bool Socket::setBlocking(bool swtch) {
    isBlocked = swtch;
    return swtch;
}

bool Socket::isClosed() {
    if(!socketIsClosed){
        char optval;
        socklen_t optlen = sizeof(optval);
        int res = getsockopt(mSocketFD,SOL_SOCKET,SO_ERROR,&optval,&optlen);
        if(optval == 0 && res == 0){
            socketIsClosed = true;
        } else{
            socketIsClosed = false;
        }
        return socketIsClosed;
    }
    else {
        return true;
    }
    
}

int Socket::getLastError() {
    return errno;
}