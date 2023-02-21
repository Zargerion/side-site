import requests
from bs4 import BeautifulSoup

# specify the url of the website you want to scrape
url = 'https://www.example.com/images/'

# send a request to the website and store the response
response = requests.get(url)

# parse the response using BeautifulSoup
soup = BeautifulSoup(response.text, 'html.parser')

# find all image tags on the page
img_tags = soup.find_all('img')

# create an empty list to store the image urls
img_urls = []

# loop through the image tags and extract the image urls
for img in img_tags:
    img_url = img['src']
    img_urls.append(img_url)

# print the first 10 image urls
print(img_urls[:10])