#!/bin/bash
# Copyright (c) Meta Platforms, Inc. and affiliates.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.

echo "Installing llava dependencies..."

# install llava from the submodule
pip install --force-reinstall -e examples/third-party/LLaVA

# not included in the pip install package, but needed in llava
pip install protobuf

# bitsandbytes depends on numpy 1.x, which is not compatible with numpy 2.x.
# Reinstall bitsandbytes to make it compatible.
pip install bitsandbytes

# The deps of llava can have different versions than deps of ExecuTorch.
# For example, torch version required from llava is older than ExecuTorch.
# To make both work, recover ExecuTorch's original dependencies by rerunning
# the install_requirements.sh.
pip install --force-reinstall torch==2.3.0 torchvision --index-url https://download.pytorch.org/whl/test/cpu

echo "Finished installing llava dependencies."
python -c 'import torch; print(f"torch version = {torch.__version__}")'
python -c 'import torchvision; print(f"torchvision version = {torchvision.__version__}")'
python -c 'import torchaudio; print(f"torchaudio version = {torchaudio.__version__}")'
pip list
