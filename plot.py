import numpy as np 
import matplotlib.pyplot as plt

nz = 648
nx = 1150

path = "data/"

model = np.fromfile(path + "conv.bin", dtype=np.float32, count=nx*nz).reshape([nz,nx], order="F")
model_python = np.fromfile(path + "test.bin", dtype=np.float32, count=nx*nz).reshape([nz,nx], order="F")
wavelet = np.fromfile(path + "wavelet.bin", dtype=np.float32)

arr = model_python
for i in range(nx):
    arr[:, i] = np.convolve(arr[:, i], wavelet, mode="same")

fig, ax = plt.subplots(nrows=1, ncols=2, figsize=(10, 5))

ax[0].imshow(model, cmap="grey")
ax[1].imshow(arr, cmap="grey")

plt.show()

