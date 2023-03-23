password = ''
user = ''

from pymongo import MongoClient

#client = MongoClient(f"mongodb+srv://{user}:{password}@dbcluster0.ov9d3zv.mongodb.net/?retryWrites=true&w=majority")

# net start mongodb net stop mongodb

client = MongoClient("mongodb://localhost:27017/")

db = client["test_db"]
collection = db["test_collection"]

from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")
def index():
    for document in collection.find():
        print(document)
    return str([document for document in collection.find()])

if __name__ == '__main__':
    app.run()


##################################

# put

from pymongo import MongoClient

client = MongoClient("mongodb://localhost:27017/")
db = client["test_db"]
collection = db["test_collection"]

with open('video.mp4', 'rb') as f:
    video_data = f.read()

collection.insert_one({'video': video_data})

# get

from pymongo import MongoClient

client = MongoClient("mongodb://localhost:27017/")
db = client["test_db"]
collection = db["test_collection"]

document = collection.find_one()
video_data = document['video']

with open('video.mp4', 'wb') as f:
    f.write(video_data)