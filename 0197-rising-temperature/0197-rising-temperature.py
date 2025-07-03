import pandas as pd

def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:
    df=pd.DataFrame(weather)
    # df=df.sort_values('recordDate')
    # df['prev_temp']=df['temperature'].shift(1)
    # res=df[df['temperature'] > df['prev_temp'] ][['id']]
    
    self_join=df.merge(df,left_on='recordDate',right_on=df['recordDate'] +pd.Timedelta(days=1),suffixes=('','_prev'))
    res=self_join[self_join['temperature'] > self_join['temperature_prev']][['id']]
    return res