var a=[1,2,3,4,5,6,3,2,4,9]
// a.push(5)
// a.push(10)
// a.pop()
// console.log(a.slice(0,2))
// var z=a.splice(1,3)
// console.log(z)
// console.log(a)
// res=a.map((each)=>{each})
// console.log(res)
// for (var i=0;i<10;i++){
//     if (a[i]%2==0){
//         console.log(a[i])
//     }
// }

// for (var i of a){
//     console.log(i)
// }

// a_s=a.sort((a,b)=>{b>a})
// console.log(a_s)

class jnani{
    constructor(name,age){
        this.name=name;
        this.age=age;
    }
    getdet(){
        console.log(this.name)
        console.log(this.age)
    }
    setname(name){
        this.name=name
    }
}

// obj1=new jnani("jnani",25)
// obj1.getdet()
// obj1.setname("jnanikumarvadigalla")
// obj1.getdet()


// const details=(name,age)=>{
//     this.name=name
//     this.age=age
// }
// details1=details("jnani",20);
// console.log(details);


map1=new Map()
set=new Set()
set.add(3)
set.add(4)
set.add(5)

// set.delete(3)
// console.log(set)
// console.log(set.values())


// map1.set("a",1)
// map1.set("b",2)
// map1.set("c",3)
// console.log(map1.delete("a"))
// console.log(2 in a)

var twoSum = function(nums, target) {
    var set=new Set()
    var s=nums.lenght
    for (var i=0;i<s;i++){
        // if (set.has(target-nums[i])){
        console.log([target-nums[i],nums[i]])
        // }
        // else{
            // set.add(nums[i])
        // }
        
    }
};

console.log(twoSum([2,7,11,15],9))

console.log(a.length)