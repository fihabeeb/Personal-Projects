from yaml import load, dump, CLoader as Loader
import json, os
path_input = r"C:\Users\fihab\Pictures\WWW\spr_atreus_hurt.yy"
directory = r"C:\Users\fihab\Pictures\WWW"
# Atreus is the name of a character in my game. Idle was a sprite name
rename = "atreus_" + "idle" + "_"
file = open(path_input,"r")
base = file.read()
ex = load(base,Loader = Loader)
fix = json.dumps(ex)
final = json.loads(fix)
for i in range (len(final["frames"])):
    for path in os.listdir(directory):
        if os.path.isfile(os.path.join(directory,path)):
            stringy = directory + "\\" + final["frames"][i]["name"] + ".png"
            pathy = directory + "\\" + path
            if pathy == stringy:
                os.rename(pathy,directory + "\\" + rename + str(i) + ".png")
file.close()
print("Done")