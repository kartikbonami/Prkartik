// const a=require("./index");

// a.average(10,20);

// a.percent(20,100);  

// const fs=require("fs");
// we can make synchronous file also ki sabse phle yh chale

// fs.readFile("./sample.txt","utf-8",(err,data)=>{
//     if(err){
//         throw err;
//     }
//     console.log(data);
// });

// console.log("I am  first");


// for synchronous file

//fs.readFileSync("./") // ase krke


// const pokemon=require("pokemon");

// console.log(pokemon.random());

const http=require("http");

const server=http.createServer((request,response,next)=>{
    res.end("working"); 
});

server.listen(4000,"localhost",()=>{
    console.log("Server is working on http://localhost:4000)");
});


