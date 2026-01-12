#pragma once

#include "../enum/matcherType.hpp"
#include "basicMatcher.hpp"
#include "interestbasedMatcher.hpp"
#include "locationBasedMatcher.hpp"
#include "matcher.hpp"

class MatcherFactory{
    public:
    static Matcher* createMatcher(MathcherType type){
        switch (type)
        {
        case MathcherType::BASIC :
            return new BasicMatcher();
            break;
        case MathcherType::INTRESTS_BASED:
            return new InteresetBasedMatcher();
            break;
        case MathcherType::LOCATION_BASED:
            return new LocationBasedMatcher();    
        
        default:
            break;
        }
        return nullptr;
    }
};