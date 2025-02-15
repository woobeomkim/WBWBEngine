#include "wbGameObject.h"
#include "wbInput.h"
#include "wbBullet.h"
#include "wbTime.h"
#include "wbTransform.h"

namespace wb
{
    GameObject::GameObject()
        :mState(eState::Active)
    {
        initializeTransform();
    }

    GameObject::~GameObject()
    {
        for (Component* comp : mComponents)
        {
            if (comp == nullptr)
                return;
            delete comp;
            comp = nullptr;
        }
    }

    void GameObject::Initialize()
    {
        for (Component* comp : mComponents)
        {
            if (comp == nullptr)
                return;
            comp->Initialize();
        }
    }

    void GameObject::Update()
    {
        for (Component* comp : mComponents)
        {
            if (comp == nullptr)
                return;
            comp->Update();
        }
    }

    void GameObject::LateUpdate()
    {
        for (Component* comp : mComponents)
        {
            if (comp == nullptr)
                return;
            comp->LateUpdate();
        }
    }

    void GameObject::Render(HDC hdc)
    {

        for (Component* comp : mComponents)
        {
            if (comp == nullptr)
                return;
            comp->Render(hdc);
        }
     
    }
    void GameObject::initializeTransform()
    {
        AddComponent<Transform>();
    }
}