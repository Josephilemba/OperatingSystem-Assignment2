import os

folder = "docs/screenshots"

if not os.path.exists(folder):
    print("Folder does not exist.")
else:

    for file in os.listdir(folder):

        if file.endswith(".png"):

            os.remove(os.path.join(folder, file))

            print(f"Deleted: {file}")

print("Old screenshots removed.")