class SBT{
    /*
    Size Balanced Tree
    */
    int N,IP,Root;
    vector<int> S,L,R,K;
    //zig = left rotate
    void zig(int &x){int t=R[x];R[x]=L[t];L[t]=x;S[t]=S[x];S[x]=S[L[x]]+S[R[x]]+1;x=t;}
    //zag = right rotate 
    void zag(int &x){int t=L[x];L[x]=R[t];R[t]=x;S[t]=S[x];S[x]=S[L[x]]+S[R[x]]+1;x=t;}
    //level = balance tree
    void level(int &x,bool flag){
        if(flag){
            if(S[L[L[x]]]>S[R[x]]) zag(x);
            else if(S[R[L[x]]]>S[R[x]]) zig(L[x]),zag(x);
            else return;
        }
        else{
            if(S[R[R[x]]]>S[L[x]]) zig(x);
            else if(S[L[R[x]]]>S[L[x]]) zag(R[x]),zig(x);
            else return;
        }
        level(L[x],true);level(R[x],false);
        level(x,true);level(x,false);
    }
    void _Insert(int &rt,int v){
        if(!rt) {rt=++IP;L[rt]=R[rt]=0;S[rt]=1;K[rt]=v;return;}
        v<=K[rt]?_Insert(L[rt],v):_Insert(R[rt],v);
        ++S[rt];level(rt,v<=K[rt]);
    }
    int _Delete(int &rt,int v){
        int Del;
        --S[rt];
        if(v == K[rt] || (v < K[rt] && !L[rt]) || (v > K[rt] && !R[rt])){
            Del=K[rt];
            if(!L[rt] || !R[rt]) rt=L[rt]+R[rt];
            else K[rt]=_Delete(L[rt],v+1);
        }
        else Del=v<K[rt]?_Delete(L[rt],v):_Delete(R[rt],v);
        level(rt,v>K[rt]);
        return Del;
    }
    int _AtRank(int &rt,int k){
        if(k==1+S[L[rt]]) return K[rt];
        return k<=S[L[rt]]?_AtRank(L[rt],k):_AtRank(R[rt],k);
    } 
    int _Rank(int &rt,int v){
        if(!rt) return 1;
        return v<=K[rt]?_Rank(L[rt],v):1+S[L[rt]]+_Rank(R[rt],v);
    }
    int _Pred(int &rt,int v){
        if(!rt) return 0;
        if(v<=K[rt]) return _Pred(L[rt],v);
        else{
            int D=_Pred(R[rt],v);
            return D?D:rt;
        }
    }
    int _Succ(int &rt,int v){
        if(!rt) return 0;
        if(v>=K[rt]) return _Succ(R[rt],v);
        else{
            int D=_Succ(L[rt],v);
            return D?D:rt;
        }
    }
    void _Show(int rt,int k){
        if(L[rt]) _Show(L[rt],k+1);
        for(int i=0;i<k;++i) printf("    ");
        printf("%d\n",K[rt]);
        if(R[rt]) _Show(R[rt],k+1);
    } 
public:
    SBT(int Size){
        N = Size;
        S = vector<int>(N+1);//Size
        L = vector<int>(N+1);//Left child
        R = vector<int>(N+1);//Right child
        K = vector<int>(N+1);//key
        S[0] = L[0] = R[0] = 0;
        IP = Root = 0;
    }
    int Size(){return S[Root];}
    void Insert(int v){_Insert(Root,v);}
    void Delete(int v){_Insert(Root,v);}
    int AtRank(int k){return _AtRank(Root,k);}
    int Rank(int v){return _Rank(Root,v);}
    int Pred(int v){return _Pred(Root,v);}
    int Succ(int v){return _Succ(Root,v);}
    void Show(){_Show(Root,0);}
};