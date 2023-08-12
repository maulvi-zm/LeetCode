class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """

        hashset = set()

        #search row
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == ".": 
                    continue
                    
                if board[i][j] in hashset:
                    return False
                else:
                    hashset.add(board[i][j])

            hashset.clear()
        
        #search column
        for i in range(len(board[0])):
            for j in range(len(board)):
                if board[j][i] == ".": 
                    continue
                    
                if board[j][i] in hashset:
                    return False
                else:
                    hashset.add(board[j][i])

            hashset.clear()
        
        #search box
        for i in range(0, len(board), 3):
            for j in range(0, len(board[0]), 3):
                for k in range(3):
                    if board[i][j+k] == ".": 
                        continue
                        
                    if board[i][j+k] in hashset:
                        return False
                    else:
                        hashset.add(board[i][j+k])
                    
                for k in range(3):
                    if board[i+1][j+k] == ".": 
                        continue
                        
                    if board[i+1][j+k] in hashset:
                        return False
                    else:
                        hashset.add(board[i+1][j+k])
                
                for k in range(3):
                    if board[i+2][j+k] == ".": 
                        continue
                        
                    if board[i+2][j+k] in hashset:
                        return False
                    else:
                        hashset.add(board[i+2][j+k])
                
                hashset.clear()
        
        return True


    
            
