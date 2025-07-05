import pandas as pd

def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    df=pd.DataFrame(employee)
    manager_counts = df['managerId'].value_counts()
    managers_with_5_or_more = manager_counts[manager_counts >= 5].index

    # Step 2: Filter employees whose managerId is in that list
    result = df[~df['managerId'].isin(managers_with_5_or_more)][['name']]
    return result