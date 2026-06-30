# Olympic Medal Prediction (MCM/ICM 2025)

Predicting Olympic medal counts using LSTM neural networks based on historical Olympic Games data (1896–2024).

## Project Structure

```
├── Data/                  # Raw and processed datasets
│   ├── summerOly_*.csv   # Original Kaggle Olympic datasets
│   ├── patch.csv         # Wide-format feature matrix
│   └── data_dictionary.csv
├── software/              # Code (Jupyter notebooks + C++)
├── output/                # Intermediate outputs
└── prediction_output/     # Final predictions
```

## Data Sources

- [120 Years of Olympic History: Athletes and Results](https://www.kaggle.com/datasets/heesoo37/120-years-of-olympic-history-athletes-and-results) (Kaggle)

## Methodology

- LSTM neural network for time-series medal prediction
- C++ data preprocessing pipeline
- Feature engineering: historical performance, host advantage, program changes

## Requirements

- Python 3.x
- PyTorch
- pandas, numpy, matplotlib, scikit-learn
