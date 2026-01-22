# Problem Statement
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.


```
Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
```

# Solution in Java

## This is not an efficient approach.

```Java
class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        List<String> result = new ArrayList<>();
        for(String word: words){
            for(int i = 0; i < board.length; i++){
                for(int j = 0; j < board[i].length; j++){
                    if(board[i][j] == word.charAt(0)){
                        if(dfs(board, i, j, 0, word)){
                            result.add(word);
                            // this is used to break out of the two loops.
                            i = board.length;
                            break;
                        }
                    }
                }
            }
        }
        
        return result;
    }
    
    
    public boolean dfs(char[][] board, int i, int j, int position, String word){
        if(position == word.length())
            return true;
        
        if(i < 0 || i >= board.length)
            return false;
        
        if(j < 0 || j >= board[i].length)
            return false;
        
        if(board[i][j] != word.charAt(position))
            return false;
        
        char temp = board[i][j];   
        board[i][j] = ' ';
        
        boolean found = dfs(board, i-1, j, position+1, word) || dfs(board, i+1, j, position+1, word) || dfs(board, i, j-1, position+1, word) || dfs(board, i, j+1, position+1, word);
        

        board[i][j] = temp;
        return found;
    }
}
```
