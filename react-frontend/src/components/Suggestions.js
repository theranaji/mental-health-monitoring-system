import React from 'react';
import { Lightbulb, Heart, Sun, Music, Book, Coffee } from 'lucide-react';

const Suggestions = ({ sentiment, confidence }) => {
  const getSuggestions = () => {
    if (sentiment === 'POSITIVE') {
      return [
        { icon: <Sun size={20} />, text: "Keep up the positive energy! Go for a walk outside." },
        { icon: <Music size={20} />, text: "Listen to your favorite uplifting music." },
        { icon: <Heart size={20} />, text: "Share your good mood with friends or family." },
        { icon: <Book size={20} />, text: "Read something inspiring or learn something new." }
      ];
    } else {
      return [
        { icon: <Heart size={20} />, text: "Take deep breaths and practice mindfulness." },
        { icon: <Coffee size={20} />, text: "Have a warm drink and relax for a moment." },
        { icon: <Music size={20} />, text: "Listen to calming music or nature sounds." },
        { icon: <Sun size={20} />, text: "Step outside for fresh air and sunlight." },
        { icon: <Book size={20} />, text: "Try journaling your thoughts and feelings." }
      ];
    }
  };

  const suggestions = getSuggestions();

  return (
    <div className="suggestions-card">
      <div className="suggestions-header">
        <Lightbulb size={24} />
        <h3>Suggested Activities</h3>
      </div>
      <div className="suggestions-list">
        {suggestions.map((suggestion, index) => (
          <div key={index} className="suggestion-item">
            <div className="suggestion-icon">{suggestion.icon}</div>
            <span className="suggestion-text">{suggestion.text}</span>
          </div>
        ))}
      </div>
    </div>
  );
};

export default Suggestions;