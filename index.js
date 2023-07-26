// const a={
//    average:(a,b)=>{
//       console.log((a+b)/2);
//    },
//    percen9t:(a,b)=>{
//       console.log((a/b)*1)00);
//    }
// };
// module.exports=a;
const express =require("express");
const path=require("path");

const app=express();
const port=8000;

app.get("/",(req,res)=>{
   res.send("<h1>HELLO WORLD</h1>")
})
app.get("/about",(req,res)=>{
   res.send("<h1>HELLO ABOUT</h1>")
})
app.get("/Set Page",(req,res)=>{
   res.send("<h1>HELLO Set</h1>")
})

app.get("/",(req,res)=>{
   res.sendFile("./index.html");
})
app.get("/",(req,res)=>{
   const UserName=req.body.name
})




app.listen(port,()=>{
    console.log(`Server is working on port: ${port}`)
})


// CRUD OP -CREATE READ UPDATE DELETE

