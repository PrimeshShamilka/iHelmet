import pandas as pd
import numpy as np

df = pd.read_csv("/media/primesh/Academics/Sem 4/Automation Challenge 2/Datasets/air-quality-madrid/csvs_per_year/csvs_per_year/madrid_2001.csv")
df = df.dropna()
dates = df["date"].values
co_data = df["CO"]
n02_date = df["NO_2"]


aqi = {"good":[0,50],"moderate":[51,100],"unhealthy_s":[101,150],"unhealthy":[151,200],"v_unhealthy":[201,300],"hazardous":[401,500]}
co = {"good":[0.0,4.4],"moderate":[4.5,9.4],"unhealthy_s":[9.5,12.4],"unhealthy":[12.5,15.4],"v_unhealthy":[15.5,30.4],"hazardous":[40.5,50.4]}
gases = {"co":co}

def calculate_aqi(gas,concentration):
       label_val = "" 
       for label in gases[gas]:
              if(co[label][0]<=concentration and co[label][1]>=concentration):
                     label_val = label
                     c_high = co[label][1]
                     c_low = co[label][0]
                     i_high = aqi[label_val][1]
                     i_low = aqi[label_val][0]
                     break
       
       aqi_val = ((i_high-i_low)*(concentration-c_low))/(c_high-c_low)+i_low

       return aqi_val


def get_aqi_list(gas,concentrations):
       aqi_list = []
       for i in concentrations:
              aqi_list.append(calculate_aqi(gas,round(i,1)))
       return aqi_list


co_aqi = get_aqi_list("co",co_data)
data = {'date': dates, 'AQI': co_aqi}
df_aqi = pd.DataFrame(data=data)
df_aqi.to_csv(r'/media/primesh/Academics/Sem 4/Automation Challenge 2/Datasets/aqi.csv',index=True)
