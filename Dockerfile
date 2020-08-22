FROM ubuntu:latest

# Set the working directory.
WORKDIR /usr/src/qounter

# Copy the file from your host to your current location.
COPY . .

# Run the command inside your image filesystem.
RUN apt-get update && apt-get install -y qt5-default qttools5-dev-tools pkg-config firefox
RUN MOC=moc UIC=uic LRELEASE=lrelease make
RUN MOC=moc UIC=uic LRELEASE=lrelease make test

# Replace 1000 with your user / group id
RUN export uid=1000 gid=1000 PATH="$PATH:/usr/sbin" && \
    mkdir -p /home/developer && \
    mkdir -p /etc/sudoers.d/ && \
    echo "developer:x:${uid}:${gid}:Developer,,,:/home/developer:/bin/bash" >> /etc/passwd && \
    echo "developer:x:${uid}:" >> /etc/group && \
    echo "developer ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/developer && \
    chmod 0440 /etc/sudoers.d/developer && \
    chown ${uid}:${gid} -R /home/developer && \
    chown ${uid}:${gid} -R /usr/src/qounter/qounter

USER developer
ENV HOME /home/developer

CMD /usr/src/qounter/qounter
