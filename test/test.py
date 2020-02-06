import pandas as pd


def recordFee():

    data=8200+8928.16+8940.55+11399.54+11547.1+14905+310+11883+11894.25+210+355+344+336+333+12058.50+348+487+11877.63+348+488+23019.97+327+96+11204.31+334+247+11504.65+335+370+11583.97+344+344+11516.43+337.15+369+366+11978.64+381+361+12610+12492
    return data

def test():
    data=pd.read_csv("record.txt",sep=" ",names=["day","lunch","dinner"])
    print(data)
    data.to_excel("record.xlsx")

print(recordFee())
print(12*2600)
