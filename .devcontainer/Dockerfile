FROM mcr.microsoft.com/devcontainers/cpp:latest

# Install additional packages
RUN sed -e "s#deb\.debian\.org#mirrors.aliyun.com#" /etc/apt/sources.list.d/debian.sources
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
    vim \
    && apt-get clean -y \
    && apt-get clean && rm -rf /var/lib/apt/lists/*
