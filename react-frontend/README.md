# Mental Health Monitoring - React Frontend

An advanced React frontend for the mental health monitoring application with sentiment analysis.

## Features

- Modern React 18 with functional components and hooks
- Real-time sentiment analysis
- Analysis history tracking
- Loading states and error handling
- Responsive design with modern UI
- Icons from Lucide React
- Axios for API communication

## Setup

1. Install dependencies:
```bash
npm install
```

2. Start the development server:
```bash
npm start
```

3. Make sure your Flask backend is running on http://127.0.0.1:5000

## Project Structure

```
src/
├── components/
│   └── SentimentAnalyzer.js    # Main analyzer component
├── services/
│   └── api.js                  # API service layer
├── styles/
│   └── index.css              # Global styles
├── App.js                     # Root component
└── index.js                   # Entry point
```

## Available Scripts

- `npm start` - Runs the app in development mode
- `npm build` - Builds the app for production
- `npm test` - Launches the test runner