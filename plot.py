import numpy as np 
import matplotlib.pyplot as plt

nz = 648
nx = 1150

path = "data/"

model = np.fromfile(path + "test.bin", dtype=np.float32, count=nx*nz).reshape([nz,nx], order="F")
model_vp = np.fromfile(path + "model_vp_2d.bin", dtype=np.float32, count=nx*nz).reshape([nz,nx], order="F")
model_rho = np.fromfile(path + "model_rho_2d.bin", dtype=np.float32, count=nx*nz).reshape([nz,nx], order="F")

model_python = np.multiply(model_vp, model_rho)

fig, ax = plt.subplots(1, 2, figsize=(10, 8))

ax[0].imshow(model)
ax[1].imshow(model_python)

plt.show()

n, q = 0, 0
for i in range(nz):
    for j in range(nx):
        if model[i][j] > 0.5:
            print(f"{model[i][j]} in index {(n, q)}")

        q += 1
    n += 1

plt.plot(model[0][:])

plt.show()

