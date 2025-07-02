import pandas as pd

def find_customers(visits: pd.DataFrame, transactions: pd.DataFrame) -> pd.DataFrame:
# 1. Filter visits that are not in transactions
    non_trans_visits = visits[~visits['visit_id'].isin(transactions['visit_id'])]

# 2. Group by customer_id and count
    result = non_trans_visits.groupby('customer_id').size().reset_index(name='count_no_trans')
    return result