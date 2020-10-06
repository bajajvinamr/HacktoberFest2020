class Node{
    constructor(value){
        this.value = value;
        this.left = null;
        this.right = null;
    }
}
class BinarySearchTree{
    constructor(){
        this.root = null;
    }
    insert(value){
        var newNode = new Node(value);
        if(this.root === null){
        this.root = newNode;
        return this;
        }
        var current = this.root;
        while(true){
            if(value === current.value) return undefined;
            if(value < current.value){
                if(current.left === null){
                    current.left = newNode;
                    return this;
                }
                current = current.left
            }else{
                if(current.right === null){
                    current.right = newNode;
                return this;
                }
                current = current.right;
                    }
                    }
            }
    find(value){
        var matchNode = new Node(value);
        if(!this.root) return undefined;
        var currentVal = this.root;
        var match = false;
        while(!match && currentVal){
            if(value < currentVal.value){
                currentVal = currentVal.left;
            }else if(value > currentVal.value){
                currentVal = currentVal.right;
                }else{
                    return true;
                }
        }
        return false;
    }
    breadFirstSearch(){
        var data = [];
        var queue = [];
        var node = this.root;
        queue.push(node);
        while(queue.length){
            node = queue.shift();
            data.push(node.value);
            if(node.left) queue.push(node.left);
            if(node.right) queue.push(node.right);}
                return data; }
    depthFirstSearchPREORDER(){
        var data = [];
        var current = this.root;
        function traverse(node){
            data.push(node.value);
            if(node.left) traverse(node.left);
            if(node.right) traverse(node.right);}
        traverse(current);
        return data;
    }
    depthFirstSearchPOSTORDER(){
        var data = [];
        var current = this.root;
        function traverse(node){
            if(node.left) traverse(node.left);
            if(node.right) traverse(node.right);
            data.push(node.value);}
            traverse(this.root);
            return data;
        }
}