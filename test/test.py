import pandas as pd


def recordFee():
    data21=4+7+3+3+2+2+5+4+12+12+3+1+5
    data212=7+5+8+5+4+3+7+3+12+6+8+4+13+6+17+6+8+13+12+6+22+12+12+25+33+16+12+20+20+9+15
    
    data=8200+8928.16+8940.55+11399.54+11547.1+14905+310+11883+11894.25+210+355+344+336+333+12058.50+348+487+11877.63+348+488+23019.97+327+96+11204.31+334+247+11504.65+335+370+11583.97+344+344+11516.43+337.15+369+366+11978.64+381+361+12610+12492
    return data21,data212

def test():
    data=pd.read_csv("record.txt",sep=" ",names=["day","lunch","dinner"])
    print(data)
    data.to_excel("record.xlsx")

print(recordFee())
print(12*2600)
