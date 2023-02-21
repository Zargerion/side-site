<template>
 <div>
    <button class="btn btn-primary" v-on:click="addLike">Good!</button>
    <button class="btn btn-primary" v-on:click="addDislike">Bad!</button>
    <button class="btn btn-primary" v-on:click="adjLike">Admin adjasting likes</button>
    <button class="btn btn-primary" v-on:click="adjDislike">Admin adjasting likes</button>
    <div>Likes: {{ likes }}</div>
    <div>Dislikes: {{ dislikes }}</div>
 </div>
 <form @submit.prevent>
  <h4>Make posts</h4>
  <input v_bind:value="title" @input="inputTitle" class="big-input" id="exampleCheck1" type="text" placeholder="name">
  <input v_bind:value="body"  @input="body = $event.target.value" class="big-input" id="exampleCheck1" type="text" placeholder="desc">
  <button class="btn btn-primary" @click="createPost">Submit!</button>
 </form>

 <div><div class="post" v-for="post in posts">
    <div><strong>Name:</strong> {{ post.title }}</div>
    <div><strong>About:</strong> {{ post.body }}</div>
 </div></div>
 <imgtion/>
</template>

<script>
  import imgtion from "./components/imgtion"
  export default {
    components: {
      imgtion
    },
    data() {
      return{
        posts: [
          {id: 1, title: 'js', body: 'description'},
          {id: 2, title: 'js', body: 'description'},
          {id: 3, title: 'js', body: 'description'}
        ],
        title: '',
        body: '',
        likes: 0,
        dislikes: 0,
      }
    },
    methods: {
      addLike() {
        this.likes += 1
      },
      addDislike() {
        this.dislikes += 1
      },
      adjLike() {
        this.likes -= 1
      },
      adjDislike() {
        this.dislikes -= 1
      },
      inputTitle(event) {
        this.title = event.target.value;
      },
      createPost() {
          const newPost = {
            id: Date.now(),
            title: this.title,
            body: this.body,
          }
          this.posts.push(newPost);
      },

    }
  }
</script>

<style>
 * {
  margin: 10px !important; 
  padding: 0 !important;
  box-sizing: border-box !important;
  text-align: center !important;
  font-family: Avenir, Helvetica, Arial, sans-serif !important;
  -webkit-font-smoothing: antialiased !important;
  -moz-osx-font-smoothing: grayscale !important;
  color: #2c3e50;
}
.post {
  padding: 5px;
  border: 1px;
  border-color: aquamarine;
  height: 100px;
  width: 80vw;
}
.big-input {
  height: 70px;
  width: 80vw;
}
</style>
