#!/bin/bash

# Pretend boot files exists
touch /boot/config.txt
touch /boot/cmdline.txt

# Grab MATRIX Repositories
curl https://apt.matrix.one/doc/apt-key.gpg | sudo apt-key add -
echo "deb https://apt.matrix.one/raspbian stretch main" | sudo tee /etc/apt/sources.list.d/matrixlabs.list

# Raspberry Pi Dependencies
sudo apt-get install -y apt-transport-https systemd
sudo apt-get update

# MATRIX Dependencies
sudo apt-get install -y cmake g++ git matrixio-creator-init libmatrixio-creator-hal libmatrixio-creator-hal-dev


# Install MATRIX HAL NFC
git clone https://github.com/matrix-io/matrix-hal-nfc.git
cd matrix-hal-nfc && mv /volume/SW297940.zip ./
./install_nxp.sh && ./build.sh
cd .. && rm -r matrix-hal-nfc


# Compile matrix-lite for desired Python 3 versions
sudo apt-get install -y python3.5-dev
compile_lite () {
    # create python3.x enviorment
    virtualenv -p python$1 --clear env && source env/bin/activate

    pip install pybind11 setuptools wheel

    # compile matrix-lite-py
    python setup.py sdist bdist_wheel
    
    # export compiled library to shared volume
    cp dist/* /volume
    
    # cleanup enviorment & changes
    deactivate
    git reset --hard && git add . && git clean -fdX
}

compile_lite 3.5
compile_lite 3.7