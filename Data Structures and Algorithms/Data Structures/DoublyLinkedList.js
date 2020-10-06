class Node{
    constructor(value){
        this.next = null;
        this.value = value;
        this.prev = null;
    }
}
class DoublyLinkedList{
    //DoublyLinkedlIST structure
    constructor(){
        this.head = null;
        this.tail = null;
        this.length = 0;
    }
    //class methodes 
    push(value){
        var newNode = new Node(value);
        if(!this.head){
            this.head = newNode;
            this.tail = this.head;
        }else{
        this.tail.next = newNode;
        newNode.prev = this.tail;
        this.tail = newNode;}
        this.length++;
        return this;}
        pop(){
            if(this.length === 1){
                this.head = null;
                this.tail = nul;
            }
            var thePoppedNode = this.tail;
            if(!this.head) return undefined;
            else{
                this.tail = thePoppedNode.prev;
                this.tail.next = null;
                thePoppedNode.prev = null;
            }
            this.length--;
            return thePoppedNode;
        }
        shift(){
            if(!this.head){
                return undefined;}
            var prevHead = this.head;
            if(this.length === 1){
                this.head = null;
                this.tail = null;}
            else{
                this.head = prevHead.next;
                this.head.prev = null;
                prevHead.next = null; }
                this.length--;
                return prevHead;}
        unshift(value){
            var newNode = new Node(value);
            if(this.length === 0){
                this.head = newNode;
                this.tail = newNode;
            }
           else{
            var oldHead = this.head;
            oldHead.prev = newNode;
            newNode.next = oldHead;
            this.head = newNode; }
            this.length++;
            return this;
        }
        get(index){
            if(index >= this.length || index < 0) return null;
            var middle = Math.floor(this.length/2);
            if(index >= middle){
                var i =this.length -1;
                var indexValue = this.tail;
                while(i!== index){
                    indexValue = indexValue.prev;
                    i--;
                }
            }
            else if(index < middle){
                var i = 0;
                var indexValue = this.head;
                while(i !== index){
                    indexValue = indexValue.next;
                    i++;
                }
            }
        return indexValue;}
        set(index, value){
            var match = this.get(index)
            if(match !== null){
            match.val = value;
            return true;}
        return false;}
        insert(index, value){
            if(index === 0)this.unshift(value);
            if(index === this.length) this.push(value);
            var newNode = new Node(value);
            var beforeNode = this.get(index-1);
            var nextNode = beforeNode.next;
            beforeNode.next = newNode;
            newNode.prev = beforeNode;
            newNode.next = nextNode;
            nextNode.prev = newNode; 
            this.length++;
            return this;
        }
        remove(index){
            //check if index is valid
            if(this.length-1 === index) this.pop();
            if(index === 0) this.shift();
            else{var currentVal = this.get(index);
            var afterCurrentVal = currentVal.next;
            var beforeCurrentVal = currentVal.prev;
            beforeCurrentVal.next - afterCurrentVal;
            afterCurrentVal.prev = beforeCurrentVal;
            currentVal.prev = null;
            currentVal.next = null;}
            this.length--;
            return currentVal;
        }
    }
        






















       