import pandas as pd
data=pd.read_csv("record.txt",sep=" ",names=["day","lunch","dinner"])
print(data)
data.to_excel("record.xlsx")