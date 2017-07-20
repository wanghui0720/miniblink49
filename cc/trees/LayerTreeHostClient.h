#ifndef cc_trees_LayerTreeHostClient_h
#define cc_trees_LayerTreeHostClient_h

namespace blink {
    class IntRect;
}

namespace cc {
    class LayerTreeHostClient {
    public:
      virtual void onLayerTreeDirty() = 0;
      virtual void onLayerTreeInvalidateRect(const blink::IntRect&) = 0;
      virtual void onLayerTreeSetNeedsCommit() = 0;

    };
}
#endif
