from google_images_search import GoogleImagesSearch
import urllib.request
import os

# create a new GoogleImagesSearch object
gis = GoogleImagesSearch('API_KEY', 'CX')
gis.search_images('dogs')
gis.results
gis.results.append(gis.results[-1])

# create a directory to save the images
if not os.path.exists("dogs"):
    os.makedirs("dogs")

# loop through the results and download the images
for i, image in enumerate(gis.results):
    if i > 100:
        break
    # download the image
    try:
        urllib.request.urlretrieve(image.url, "dogs/dog"+str(i)+".jpg")
    except:
        pass