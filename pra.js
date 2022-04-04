function allpos(arr,i,n,out){
    
    if (i>=n) return out
    let k;
    
    for (k of [...out]){
        
        a=k.concat([arr[i]])
        out.push(a)
    }
    
    return allpos(arr,i+1,n,out)
}

console.log(allpos([1,2,3,4,5],0,5,[[]]))
        

// var a=[[]]
// a[0].push(10)
// a[0]=a[0].concat([2])
// console.log(a[0])
    