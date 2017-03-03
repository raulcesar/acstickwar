#include "CCParallaxNodeExtras.h"

// Hack to access CCPointObject (which is not a public class)
class PointObject : public Ref
{
  public:
    inline void setRation(Point ratio) { _ratio = ratio; }
    inline void setOffset(Point offset) { _offset = offset; }
    inline void setChild(Node *var) { _child = var; }
    inline Point getOffset() const { return _offset; }
    inline Node *getChild() const { return _child; }
  private:
    Point _ratio;
    Point _offset;
    Node *_child;
};

// Need to provide a constructor
CCParallaxNodeExtras::create()
{
    // Create an instance of InfiniteParallaxNode
    CCParallaxNodeExtras *node = new CCParallaxNodeExtras();
    if (node)
    {
        // Add it to autorelease pool
        node->autorelease();
    }
    else
    {
        // Otherwise delete
        delete node;
        node = 0;
    }
    return node;
}

void CCParallaxNodeExtras::updatePosition()
{
    int safeOffset = -10;
    // Get visible size
    Size visibleSize = Director::getInstance()->getVisibleSize();
    // 1. For each child of an parallax node
    for (int i = 0; i < _children.size(); i++)
    {
        auto node = _children.at(i);
        // 2. We check whether it is out of the left side of the visible area
        if (convertToWorldSpace(node->getPosition()).x + node->getContentSize().width < safeOffset)
            // 3. Find PointObject that corresponds to current node
            for (int i = 0; i < _parallaxArray->num; i++)
            {
                auto po = (PointObject *)_parallaxArray->arr[i];
                // If yes increase its current offset on the value of visible width
                if (po->getChild() == node)
                    po->setOffset(po->getOffset() +
                                  Point(visibleSize.width + node->getContentSize().width, 0));
            }
    }
}

// ::incrementOffset(CCPoint offset, CCNode *node)
// {
//     auto m_pParallaxArray = this->getParallaxArray();
//     CCLOG("YO MAN %d", m_pParallaxArray->num);

//     for (unsigned int i = 0; i < m_pParallaxArray->num; i++)
//     {
//         CCPointObject *point = (CCPointObject *)m_pParallaxArray->arr[i];

//         if (point != NULL)
//         {
//             // CCNode *curNode = point->getChild();
//         }

//         //     if (curNode == node)
//         //     {
//         //         point->setOffset(ccpAdd(point->getOffset(), offset));
//         //         break;
//         //     }
//     }
// }