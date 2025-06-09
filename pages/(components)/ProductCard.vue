<script setup lang="ts">
defineProps({
    name: String,
    producer: String,
    distributor: String,
    description: String,
    synopsis: String,
    image: String,
    tags: Array<String>,
    price: Number
})

export type ProductCardType = {
    name: string
    producer: string
    distributor: string
    description: string
    synopsis: string
    image: string
    tags: Array<string>
    price: number
}

export type ProductCardMutationType = ProductCardType & {
    id: number
    quantity: number
    discount?: number
    availability: boolean
    webviewPath: string
}

const emits = defineEmits(['addToShoppingCart', 'removeFromShoppingCart'])

const inShoppingCartAlready = ref(false)

const addProductToCart = computed(() => {
    emits('addToShoppingCart')
})

const removeProductFromCart = computed(() => {
    emits('removeFromShoppingCart')
})
</script>

<template>
    <article
        class="max-w-sm max-h-md rounded-b rounded-md shadow-lg text-[#0e020c] bg-[#f1eae4]"
    >
        <section class="px-2 py-1">
            <h1
                class="text-lg text-justify text-start font-light font-stretch-ultra-expanded italic"
            >
                {{ name }}
            </h1>

            <span>
                by
                <i>{{ producer }}</i>
            </span>
        </section>

        <img
            v-bind:src="image"
            alt="Card focus-hero portrait"
            class="max-w-full ma-h-xs px-1 rounded rounded-sm"
        />

        <div class="px-6 pt-4 pb-2">
            <span
                class="inline-block bg-[#446a4b] rounded-full px-2 py-1 text-sm text-[#f1eae4] mr-2 mb-2"
                v-for="tag in tags"
            >
                <i>{{ tag }}</i>
            </span>
        </div>

        <section class="px-6 py-4">
            <p class="font-medium text-md mb-2">{{ description }}</p>
        </section>

        <code class="px-6 py-4">{{ price }}</code>

        <div v-if="inShoppingCartAlready == true">
            <button class="px-6 py-4" @onclick="removeProductFromCart">
                Remove from cart? &ominus;
            </button>
        </div>

        <button class="px-6 py-4" @onclick="addProductToCart">
            Add to cart? &oplus;
        </button>
    </article>
</template>
