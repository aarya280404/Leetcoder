import pandas as pd

def employee_bonus(employee: pd.DataFrame, bonus: pd.DataFrame) -> pd.DataFrame:
    emp=pd.DataFrame(employee)

    merge=pd.merge(emp,bonus,on='empId',how='left')
    res=merge[(merge['bonus'] < 1000) | (merge['bonus'].isnull())][['name','bonus']]
    return res
    