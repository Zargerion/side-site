from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
import os
import urllib.request

# specify the url of the Google Images
url = "https://www.google.com/imghp"

# create a new Chrome browser instance
driver = webdriver.Chrome()

# navigate to the Google Images website
driver.get(url)

# find the search box element
search_box = driver.find_element("xpath", "/html/body/div[1]/div[3]/form/div[1]/div[1]/div[1]/div/div[2]/input")

# enter the search term in the search box
search_box.send_keys("dogs")

# press the enter key to start the search
search_box.send_keys(Keys.RETURN)

# wait for the search results to load
driver.implicitly_wait(10)

# find all image thumbnail elements
thumbnail_elements = driver.find_elements(By.CSS_SELECTOR, "img.rg_i")

# create a directory to save the images
if not os.path.exists("dogs"):
    os.makedirs("dogs")

# loop through the thumbnail elements and download the images
for i, thumbnail_element in enumerate(thumbnail_elements):
    if i > 9:
        break

    # get the image source url
    img_url = thumbnail_element.get_attribute("src")

    # download the image
    if img_url:
        try:
            urllib.request.urlretrieve(img_url, "dogs/dog"+str(i)+".jpg")
        except:
            pass


# close the browser
driver.close()