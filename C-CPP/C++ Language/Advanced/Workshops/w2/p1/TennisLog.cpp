#include"TennisLog.h"

namespace sdds{
    TennisMatch::TennisMatch(){
        m_TID="undefined";
        m_MID=0;
        m_MLoser="undefined";
        m_MWinner="undefined";
        m_TName="undefined";
    }
    
    TennisMatch::TennisMatch(std::string tId,std::string tName,int mId,std::string winnerName,std::string loserName){
        m_TID=tId;
        m_MLoser=loserName;
        m_MWinner=winnerName;
        m_TName=tName;
        m_MID=mId;
    }
    std::ostream& operator<<(std::ostream& os,TennisMatch t)
    {
	if(t.m_TID=="undefined")os<<"Empty Match";
	else{
        os<<std::right<<std::setw(20)<<std::setfill('.')<<"Tourney ID"<<" : "<<std::left<<std::setw(30)<<std::setfill('.')<<t.m_TID<<"\n";
        os<<std::right<<std::setw(20)<<std::setfill('.')<<"Match ID"<<" : "<<std::left<<std::setw(30)<<std::setfill('.')<<t.m_MID<<"\n";
        os<<std::right<<std::setw(20)<<std::setfill('.')<<"Tourney"<<" : "<<std::left<<std::setw(30)<<std::setfill('.')<<t.m_TName<<"\n";
        os<<std::right<<std::setw(20)<<std::setfill('.')<<"Winner"<<" : "<<std::left<<std::setw(30)<<std::setfill('.')<<t.m_MWinner<<"\n";
        os<<std::right<<std::setw(20)<<std::setfill('.')<<"Loser"<<" : "<<std::left<<std::setw(30)<<std::setfill('.')<<t.m_MLoser<<"\n";
}
        return os;
    }
    TennisMatch& TennisMatch::operator=(const TennisMatch& t){
        m_TID=t.m_TID;
        m_MLoser=t.m_MLoser;
        m_MWinner=t.m_MWinner;
        m_TName=t.m_TName;
        m_MID=t.m_MID;
        return *this;
    }
    TennisMatch::~TennisMatch(){

    }

    TennisLog::TennisLog(){
        m_arr=nullptr;
        m_size=0;
    }
    TennisLog::TennisLog(std::string filename){
        std::ifstream fptr(filename);
        
        int i=-1;
        std::string str;
        int numOfRecords=0;
        if(!fptr.is_open()){
            std::cout<<"\n\n!*********ERROR OPENING FILE*********!\n\n"; 
            return;
        }
        while(std::getline(fptr,str,'\n'))
        {
            numOfRecords++;
        }
        m_size=numOfRecords-1;
        m_arr=new TennisMatch[numOfRecords];
        fptr.close();
        fptr.open(filename);

        std::getline(fptr,str,'\n');//to eliminate the field name entry
        while(++i<numOfRecords)
        {
            std::getline(fptr,m_arr[i].m_TID,',');
            std::getline(fptr,m_arr[i].m_TName,',');
            std::getline(fptr,str,',');
		
            m_arr[i].m_MID=stoi(str);
            std::getline(fptr,m_arr[i].m_MWinner,',');
            std::getline(fptr,m_arr[i].m_MLoser,'\n');
        }
        fptr.close();
    }
    void TennisLog::addMatch(TennisMatch t){
        TennisMatch* newArr=new TennisMatch[m_size+1];
        int i=0;
        for(i=0;i<m_size;i++)
        {
            newArr[i]=m_arr[i];
        }
        newArr[i]=t;
	m_size++;
        delete[] m_arr;
        m_arr=newArr;
    }
    TennisLog TennisLog::findMatches(std::string name){
        int counter=0;
        TennisLog res{};
        for(int i=0;i<m_size;i++)
        {
            if(m_arr[i].m_MWinner==name || m_arr[i].m_MLoser==name ) counter++;
        }
        res.m_arr=new TennisMatch[counter];
        for(int i=0,k=0;i<m_size;i++)
        {
            if(m_arr[i].m_MWinner==name || m_arr[i].m_MLoser==name ) {
                res.m_arr[k++]=m_arr[i];
            }
        }
	res.m_size=counter;
        return res;
    }
    TennisMatch TennisLog::operator[](size_t idx){
	TennisMatch res;
        return m_arr==nullptr?res:m_arr[idx];
    }
    TennisLog::operator size_t(){

        return m_size;
    }
    TennisLog::~TennisLog(){
        delete[] m_arr;
        m_arr=nullptr;
    }
}