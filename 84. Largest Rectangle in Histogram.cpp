class Solution {
public:
    //using 2 stack. so the logic is..
    //1) if stack is empty just push the index and height
    //2) if current height is greater than previous height then this new bigger height can give us a much higher area so pushing it in stack. (that previous height still stays in stack as it also can give higher area)
    //3) if current height is smaller then this means that our current smaller height is not good for our prevoius higher height so we need to computer previous height area. also removing & computing all those height which are in top of stack which are smaller than our current height.. now for our current height index will be the index of last previous top of stack index as it was bigger height so our current small height can take that same small height from that bigger height! 
    //
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0) return 0;
        stack<int> Hstack,Pstack; //for height and index position stack
        int maxarea=INT_MIN;
        int i;
        for(i=0;i<heights.size();++i)
        {
            if(Hstack.empty() || Hstack.top()<heights[i]) //if stack is empty or current height is bigger so this new height can form a bigger area so pushing it in stack
            {
                Hstack.push(heights[i]);
                Pstack.push(i);
            }
            else
            { 
                int TopIndex,TopHeight;
                while(Hstack.size() && Hstack.top()>=heights[i]) //removing and computing all those heights which are smaller than our current height
                {
                    
                    TopIndex=Pstack.top();
                    TopHeight=Hstack.top();
                    Pstack.pop();
                    Hstack.pop();
                    maxarea=max(maxarea,(i-TopIndex)*TopHeight);
                }
                //now pushing current height with index of previous bigger height as that bigger height can be used for our current index height
                Hstack.push(heights[i]); 
                Pstack.push(TopIndex);
                
            }
                
        }
        while(Hstack.size()) //if there is something remain in stack then compute it
        {
            maxarea=max(maxarea,(i-Pstack.top())*Hstack.top());
            Hstack.pop();
            Pstack.pop();
        }
        
        return maxarea;
    }
};