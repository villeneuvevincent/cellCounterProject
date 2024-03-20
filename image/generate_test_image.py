from argparse import ArgumentParser

parser = ArgumentParser()
parser.add_argument('pixels', nargs='+')
args = parser.parse_args()

pixels = args.pixels

for row in pixels[1:]:
    assert len(row) == len(pixels[0]), "Toutes les lignes doivent etre de meme longueur"

header = "P5"
nb_lignes = len(pixels)
nb_colonnes = len(pixels[0])
depth = "255"

with open("image.pgm", "wb") as PGM_file:
    PGM_file.write("{}\n".format(header).encode("ascii"))
    PGM_file.write("{} {}\n".format(nb_lignes, nb_colonnes).encode("ascii"))
    PGM_file.write("{}\n".format(depth).encode("ascii"))
    for ligne in pixels:
        for pixel in ligne:
            if pixel == "N":
                PGM_file.write(b"\x00")
            elif pixel == "B":
                PGM_file.write(b"\xFF")
            else:
                raise ValueError("Pixel sould be 'N' or 'B'")
