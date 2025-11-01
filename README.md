# Mental Health Monitoring System

A full-stack web application for mental health monitoring with AI-powered sentiment analysis and personalized activity suggestions.

## Features

- **User Authentication** - Secure login/signup system
- **Sentiment Analysis** - AI-powered mood detection using HuggingFace transformers
- **Activity Suggestions** - Personalized recommendations based on mood
- **Analysis History** - Track your mental health journey
- **Modern UI** - Responsive React interface with smooth animations

## Tech Stack

### Backend
- **Python Flask** - REST API framework
- **HuggingFace Transformers** - AI sentiment analysis
- **Flask-CORS** - Cross-origin resource sharing
- **PyTorch** - Machine learning framework

### Frontend
- **React 18** - Modern JavaScript UI library
- **Axios** - HTTP client for API communication
- **Lucide React** - Beautiful icons
- **CSS3** - Modern styling with gradients

## Installation & Setup

### Backend Setup
```bash
cd backend
pip install -r requirements.txt
python app.py
```

### Frontend Setup
```bash
cd react-frontend
npm install
npm start
```

## Usage

1. **Sign Up/Login** - Create account or login
2. **Share Thoughts** - Enter your feelings in the text area
3. **Get Analysis** - AI analyzes your sentiment
4. **View Suggestions** - Get personalized activity recommendations
5. **Track History** - Monitor your mental health journey

## API Endpoints

- `POST /analyze` - Analyze sentiment of text input

## Project Structure

```
mental-health-monitoring/
├── backend/
│   ├── app.py              # Flask API server
│   └── requirements.txt    # Python dependencies
├── react-frontend/
│   ├── src/
│   │   ├── components/     # React components
│   │   ├── services/       # API services
│   │   └── styles/         # CSS styles
│   └── package.json        # Node dependencies
└── README.md
```

## Contributing

1. Fork the repository
2. Create your feature branch
3. Commit your changes
4. Push to the branch
5. Create a Pull Request

## License

This project is open source and available under the MIT License.