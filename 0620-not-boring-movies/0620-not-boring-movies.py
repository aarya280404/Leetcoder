import pandas as pd

def not_boring_movies(cinema: pd.DataFrame) -> pd.DataFrame:
    df=pd.DataFrame(cinema)
    res=df[(df['id'] %2 !=0) & (df['description'] != 'boring')][['id','movie','description','rating']].sort_values(by='rating',ascending=False)
    return res