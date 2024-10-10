import numpy as np 
import matplotlib.pyplot as plt

nz = 648
nx = 1150

path = "data/"

model = np.fromfile(path + "conv.bin", dtype=np.float32, count=nx*nz).reshape([nz,nx], order="F")
model_vp = np.fromfile(path + "model_vp_2d.bin", dtype=np.float32, count=nx*nz).reshape([nz,nx], order="F")
model_rho = np.fromfile(path + "model_rho_2d.bin", dtype=np.float32, count=nx*nz).reshape([nz,nx], order="F")

model_python = np.fromfile(path + "test.bin", dtype=np.float32, count=nx*nz).reshape([nz,nx], order="F")

fig, ax = plt.subplots(1, 2, figsize=(10, 8))

ax[0].imshow(model, cmap="grey")
ax[1].imshow(model_python)

plt.show()

wavelet = np.fromfile(path + "wavelet.bin", dtype=np.float32)

arr = model_python
for i in range(nx):
    arr[:, i] = np.convolve(arr[:, i], wavelet, mode="same")

plt.imshow(arr, cmap="grey")

plt.show()
