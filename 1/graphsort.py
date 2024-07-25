import pandas as pd
import matplotlib.pyplot as plt

merge = pd.read_csv('merge.csv')
quick = pd.read_csv('quick.csv')

plt.plot(merge['size'], merge['Ascending'], label='Merge Sort Ascending')
plt.plot(merge['size'], merge['Descending'], label='Merge Sort Descending')
plt.plot(merge['size'], merge['Random'], label='Merge Sort Random')
plt.plot(quick['size'], quick['Ascending'], label='Quick Sort Ascending')
plt.plot(quick['size'], quick['Descending'], label='Quick Sort Descending')
plt.plot(quick['size'], quick['Random'], label='Quick Sort Random')
plt.legend()
plt.xlabel('Size')
plt.ylabel('Time')
plt.title('Merge vs Quick comparison')
plt.show()